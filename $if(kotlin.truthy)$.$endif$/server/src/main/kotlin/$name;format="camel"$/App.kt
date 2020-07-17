package $name;format="camel"$

import org.http4k.core.Request
import org.http4k.core.Method
import org.http4k.core.Response
import org.http4k.core.Status.Companion.OK
import org.http4k.routing.bind
import org.http4k.routing.routes
import org.http4k.server.Jetty
import org.http4k.server.asServer

fun main() {
    App.counterServer().start().block()
}

object App {
    fun counterServer(port: Int = 8080) = CounterApi.routes.asServer(Jetty(port))
}
object CounterApi{

    var sharedCounter = 0;

    val routes = routes(
        "/counter" bind Method.GET to {_: Request -> Response(OK).body(sharedCounter.toString())},
        "/increment" bind Method.POST to { _: Request ->   sharedCounter += 1; Response(OK).body(sharedCounter.toString()) },
        "/decrement" bind Method.POST to { _: Request ->   sharedCounter += -1; Response(OK).body(sharedCounter.toString()) }
    )
}